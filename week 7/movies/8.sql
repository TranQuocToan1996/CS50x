select people.name from people where id in
(select stars.person_id from stars join movies
on stars.movie_id = movies.id and title = 'Toy Story');