# Write your MySQL query statement below
select
    a. activity_date as day,
    count(distinct user_id) as active_users
from
    Activity a
where
    datediff('2019-07-27', a.activity_date) between 0 and 29
group by
    a.activity_date