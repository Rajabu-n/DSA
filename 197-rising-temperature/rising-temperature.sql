# Write your MySQL query statement below
select w.id from Weather as w JOIN Weather as y ON w.recordDATE=DATE_ADD(y.recordDATE, interval 1 DAY) where w.temperature>y.temperature;