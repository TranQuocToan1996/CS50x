select title from movies
join stars on stars.movie_id = movies.id
join people on people.id = stars.person_id
join ratings on ratings.movie_id = movies.id
where people.name ='Chadwick Boseman'
order by ratings.rating desc
limit 5;