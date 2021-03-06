create user "user1" with sysadmin password 'Gaussdba@Mpp';
set role "user1" password 'Gaussdba@Mpp';
create table t1 (a int ,b int);
select * from DBA_TABLES where table_name = 't1';
select * from DBA_TAB_COLUMNS where table_name = 't1';
insert into t1 values (2,5);
analyze t1;
select * from DBA_TABLES where table_name = 't1';
select * from DBA_TAB_COLUMNS where table_name = 't1';
create table t2 (a int ,b int NOT NULL, c number,d number(2),e number(3,2));
select * from DBA_TAB_COLUMNS where table_name = 't2';
CREATE INDEX t1_index ON t1 (a);
select * from DBA_INDEXES where index_name = 't1_index';
select * from DBA_IND_COLUMNS where index_name = 't1_index';
select * from DBA_IND_EXPRESSIONS where index_name = 't1_index';
create table t3 (a int primary key, b int);
select * from DBA_INDEXES where table_name = 't3';
select * from DBA_CONSTRAINTS where table_name = 't3';
select * from DBA_CONS_COLUMNS where table_name = 't3';
create table t4 (a varchar(32), b varchar(32));
create index t4_index_expression on t4 ((a||' '||b));
select * from DBA_IND_COLUMNS where index_name = 't4_index_expression';
select * from DBA_IND_EXPRESSIONS where index_name = 't4_index_expression';
alter table t1 add constraint pk1 primary key (a);
select * from DBA_CONS_COLUMNS where table_name = 't1';
create table t5 (a char ,b VARCHAR2(20), c NCHAR,d NVARCHAR2(20), e int);
select * from DBA_TAB_COLUMNS where table_name = 't5';
insert into t5 values ('1','3333333','2','4eddd',1);
analyze t5;
select * from DBA_TAB_COLUMNS where table_name = 't5';
create table t6 (a int , b int);
create index t6_index on t6 (trunc(a),trunc(b));
select * from DBA_IND_EXPRESSIONS where table_name = 't6';
select * from DBA_IND_COLUMNS where table_name = 't6';
comment on table t6 is 'test table';
comment on column t6.a is 'column a';
select * from DBA_TAB_COMMENTS where table_name = 't6';
select * from DBA_TAB_COMMENTS where table_name = 't5';

create user "user2" with sysadmin password 'Gaussdba@Mpp';
set role "user2" password 'Gaussdba@Mpp';

select * from USER_TABLES where table_name = 't1';
select * from USER_TAB_COLUMNS where table_name = 't1';
select * from USER_INDEXES where index_name = 't1_index';
select * from USER_IND_COLUMNS where index_name = 't1_index';
select * from USER_CONSTRAINTS where table_name = 't3';
select * from USER_CONS_COLUMNS where table_name = 't3';
select * from USER_IND_EXPRESSIONS where index_name = 't4_index_expression';
select * from USER_TAB_COMMENTS where table_name = 't6';

set role "user1" password 'Gaussdba@Mpp';

drop table t1;
drop table t2;
drop table t3;
drop table t4;
drop table t5;
drop table t6;
reset role;
drop user "user1";
drop user "user2";
