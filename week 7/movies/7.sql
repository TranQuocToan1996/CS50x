select movies.title, ratings.rating from movies join ratings
on movies.id=ratings.movie_id and movies.year = 2010
order by ratings.rating desc, movies.title asc;