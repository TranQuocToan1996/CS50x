select avg(rating) from ratings join movies
on movie_id = id and year = 2012;