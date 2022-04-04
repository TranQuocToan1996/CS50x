select distinct people.name from people
join directors on directors.person_id = people.id
join ratings on ratings.movie_id = directors.movie_id
where ratings.rating >= 9;