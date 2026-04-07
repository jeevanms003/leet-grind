select c.customer_id , COUNT(c.visit_id) as count_no_trans from visits c
left join transactions t on t.visit_id = c.visit_id
where t.transaction_id is NULL
group by c.customer_id