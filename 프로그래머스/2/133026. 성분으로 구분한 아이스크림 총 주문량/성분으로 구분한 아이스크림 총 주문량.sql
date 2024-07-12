-- 코드를 입력하세요
# select * from first_half join icecream_info on first_half.flavor = icecream_info.flavor;

SELECT
         b.ingredient_type
       , sum(a.total_order)        
    from FIRST_HALF a
    join ICECREAM_INFO b ON a.flavor = b.flavor
    group by b.ingredient_type 
    order by total_order;