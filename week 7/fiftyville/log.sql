-- running .tables
-- airports
-- crime_scene_reports
-- people
-- atm_transactions
-- flights
-- phone_calls
-- bank_accounts
-- interviews
-- courthouse_security_logs
-- passengers



-- Taking all information related to the date of crime
select * from crime_scene_reports
where month = 7 and day = 28 and street ="Chamberlin Street";
-- id | year | month | day | street | description
-- 295 | 2020 | 7 | 28 | Chamberlin Street | Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.



-- Reading the interview of 3 witnesses
select * from interviews
where month = 7 and day = 28;
-- id | name | year | month | day | transcript
-- 158 | Jose | 2020 | 7 | 28 | “Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
-- 159 | Eugene | 2020 | 7 | 28 | “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”
-- 160 | Barbara | 2020 | 7 | 28 | “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.
-- 161 | Ruth | 2020 | 7 | 28 | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- 162 | Eugene | 2020 | 7 | 28 | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- 163 | Raymond | 2020 | 7 | 28 | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.



-- Find where the theft go first by watch the security logs at the time around the event happens, taking information about exit car license_plate:
select * from courthouse_security_logs
where month = 7 and day = 28 and hour = 10 and (25 >= minute);
-- id | year | month | day | hour | minute | activity | license_plate
-- 258 | 2020 | 7 | 28 | 10 | 8 | entrance | R3G7486
-- 259 | 2020 | 7 | 28 | 10 | 14 | entrance | 13FNH73
-- 260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
-- 261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
-- 262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
-- 263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
-- 264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
-- 265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
-- 266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
-- 267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55




select license_plate from courthouse_security_logs
where month = 7 and day = 28 and hour = 10 and (25 >= minute) and activity = 'exit';
-- 5P2BI95
-- 94KL13X
-- 6P58WS2
-- 4328GD8
-- G412CB7
-- L93JTIZ
-- 322W7JE
-- 0NTHK55




-- Find the owner of the car
select name,id from people where license_plate in (select license_plate from courthouse_security_logs  where month = 7 and day = 28 and hour = 10 and (25 >= minute) and activity = 'exit');
-- Patrick | 221103
-- Amber | 243696
-- Elizabeth | 396669
-- Roger | 398010
-- Danielle | 467400
-- Russell | 514354
-- Evelyn | 560886
-- Ernest | 686048



-- Watch the bank account and atm_transactions:
select * from atm_transactions
where month = 7 and day = 28 and year = 2020
and transaction_type = 'withdraw' and atm_location = 'Fifer Street';
-- id | account_number | year | month | day | atm_location | transaction_type | amount
-- 246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
-- 264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
-- 267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
-- 269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
-- 288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
-- 336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35



-- Find the one who withdraw money in the Fifer street and compare with the owner of the car:
select person_id from bank_accounts
where account_number in
(select account_number  from atm_transactions
where month = 7 and day = 28 and year = 2020
and transaction_type = 'withdraw' and atm_location = 'Fifer Street');
-- 686048
-- 514354
-- 458378
-- 395717
-- 396669
-- 467400
-- 449774
-- 438727

-- Now theft sus maybe:
-- Elizabeth | 396669
-- Danielle | 467400
-- Russell | 514354
-- Ernest | 686048




-- Investigate about the soonest fight
select * from flights
where month = 7 and day = 29 and year = 2020;
-- id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
-- 18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0
-- 23 | 8 | 11 | 2020 | 7 | 29 | 12 | 15
-- 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20
-- 43 | 8 | 1 | 2020 | 7 | 29 | 9 | 30
-- 53 | 8 | 9 | 2020 | 7 | 29 | 15 | 20

select * from flights
where month = 7 and day = 29 and year = 2020
order by hour
limit 1;
-- id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
-- 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20

select * from airports;
-- id | abbreviation | full_name | city
-- 1 | ORD | O'Hare International Airport | Chicago
-- 2 | PEK | Beijing Capital International Airport | Beijing
-- 3 | LAX | Los Angeles International Airport | Los Angeles
-- 4 | LHR | Heathrow Airport | London
-- 5 | DFS | Dallas/Fort Worth International Airport | Dallas
-- 6 | BOS | Logan International Airport | Boston
-- 7 | DXB | Dubai International Airport | Dubai
-- 8 | CSF | Fiftyville Regional Airport | Fiftyville
-- 9 | HND | Tokyo International Airport | Tokyo
-- 10 | CDG | Charles de Gaulle Airport | Paris
-- 11 | SFO | San Francisco International Airport | San Francisco
-- 12 | DEL | Indira Gandhi International Airport | Delhi




select id,city from airports
where airports.id =
(select destination_airport_id from flights
where month = 7 and day = 29 and year = 2020
order by hour
limit 1);
-- id | city
-- 4 | London




-- Find the theft through the passengers passport number, compare with the sus above. Because one of  witness said ‘They’, so that theft maybe more than 1:
select name from people
where passport_number in (select passport_number from passengers
where flight_id = 36);
-- id | name | phone_number | passport_number | license_plate
-- 395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN
-- 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
-- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
-- 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8 | 7B
-- 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
-- 651714 | Edward | (328) 555-1152 | 1540955065 | 130LD9Z
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X |4A
-- 953679 | Doris | (066) 555-9701 | 7214083635 | M51FA04



-- Check the phone call for the accomplice
select caller, receiver from phone_calls
where year = 2020 and month =7 and day =28 and duration <= 60;
-- caller | receiver
-- (130) 555-0289 | (996) 555-8899
-- (499) 555-9472 | (892) 555-8872
-- (367) 555-5533 | (375) 555-8161 | Ernest
-- (609) 555-5876 | (389) 555-5198
-- (499) 555-9472 | (717) 555-1342
-- (286) 555-6063 | (676) 555-6554
-- (770) 555-1861 | (725) 555-3243
-- (031) 555-6622 | (910) 555-3251
-- (826) 555-1652 | (066) 555-9701
-- (338) 555-6650 | (704) 555-2131
select name from people
where phone_number = '(375) 555-8161';
-- name
-- Berthold


