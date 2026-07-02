# Write your MySQL query statement below
select r.contest_id,ROUND(count(r.user_id)*100.0/(select count(*) from users ),2) as percentage from Register r 
group by contest_id order by percentage desc ,contest_id;