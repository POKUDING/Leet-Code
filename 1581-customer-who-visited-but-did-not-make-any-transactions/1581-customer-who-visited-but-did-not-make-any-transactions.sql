select customer_id, COUNT(V.visit_id) AS count_no_trans
-- select *
from Visits V left join Transactions T on V.visit_id=T.visit_id
where T.transaction_id is null
group by V.customer_id