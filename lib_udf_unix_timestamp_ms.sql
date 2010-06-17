/**
 * mysql> select unix_timestamp_ms() * 1000 / 1000;
 * +-----------------------------------+
 * | unix_timestamp_ms() * 1000 / 1000 |
 * +-----------------------------------+
 * |                   1276753745.7377 |
 * +-----------------------------------+
 * 1 row in set (0.00 sec)
 */

drop function if exists unix_timestamp_ms;

create function unix_timestamp_ms returns real soname 'lib_udf_unix_timestamp_ms.so';
