-- 코드를 작성해주세요
-- fish info는 fish_name_info 테이블에서 bass, snapper에 해당하는 fish_type을 조건문으로 받으면 됨
select count(*) as FISH_COUNT
  from fish_info
 where fish_type in (select fish_type from fish_name_info where fish_name in ('BASS', 'SNAPPER'));