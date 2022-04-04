select count(id) from movies join ratings
on (id = movie_id and rating = 10);