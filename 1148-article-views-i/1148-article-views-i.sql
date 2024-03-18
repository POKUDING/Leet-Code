# Write your MySQL query statement below
select author_id "id" from Views where author_id=viewer_id group by article_id order by id