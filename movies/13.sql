select distinct(name) from people
join stars on stars.person_id = people.id
join movies on movies.id = stars.movie_id
where title in
(select title from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where birth = 1958 and name = "Kevin Bacon")
and name != "Kevin Bacon";