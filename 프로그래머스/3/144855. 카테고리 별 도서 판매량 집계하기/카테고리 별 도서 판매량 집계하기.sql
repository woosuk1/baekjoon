-- 코드를 입력하세요


# select 
#          *
#     from book
#     join book_sales on book.book_id = book_sales.book_id
#     group by book.category
#     ;
    

SELECT
        a.category as CATEGORY
      , sum(b.sales) as TOTAL_SALES
    from book a
    join book_sales b on a.book_id = b.book_id
    where b.sales_date between '2022-01-01 00:00:00' and '2022-01-31 23:59:59'
    group by a.category
    order by a.category
    ;