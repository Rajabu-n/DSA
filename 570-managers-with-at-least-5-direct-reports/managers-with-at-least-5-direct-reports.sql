# Write your MySQL query statement below
select e.name from Employee e JOIN Employee s ON e.id=s.managerId
group by s.managerId having count(s.managerId)>=5;