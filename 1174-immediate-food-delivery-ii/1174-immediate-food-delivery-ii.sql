# Write your MySQL query statement below
select
    round(avg(if(p=o, 1, 0)) * 100, 2) immediate_percentage
from (
    select 
        min(customer_pref_delivery_date) as p, min(order_date) as o
    from
        Delivery
    group by
        customer_id
    ) first