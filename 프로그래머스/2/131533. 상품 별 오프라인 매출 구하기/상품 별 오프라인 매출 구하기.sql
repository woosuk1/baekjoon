-- 코드를 입력하세요
SELECT
      #   sum(b.sales_amount)
      # , a.price
      a.product_code
      , (sum(b.sales_amount) * a.price) as sales
    from product a
    join offline_sale b 
    on a.product_id = b.product_id
    group by a.product_code
    order by sales desc, a.product_code;
   ;