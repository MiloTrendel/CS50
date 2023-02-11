select title from movies
join stars on movies.id = stars.movie_id
join ratings on stars.movie_id = ratings.movie_id
join people on stars.person_id = people.id
where name = "Chadwick Boseman"
order by rating DESC
limit 5;