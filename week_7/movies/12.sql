select title from movies where id in (select movie_id from stars where person_id in (select id from people where name = "Helena Bonham Carter")intersect select movie_id from stars where person_id in (select id from people where name =  "Johnny Depp"));