----
-- phpLiteAdmin database dump (http://www.phpliteadmin.org/)
-- phpLiteAdmin version: 1.9.7.1
-- Exported: 8:00pm on March 27, 2026 (CET)
-- database file: ./demo/1cb1b67629e37ee/Chinook_Sqlite.sqlite
----
BEGIN TRANSACTION;

----
-- Table structure for books
----
CREATE TABLE 'books' ('id' INTEGER PRIMARY KEY NOT NULL DEFAULT NULL, 'name' TEXT, 'pages' INTEGER, 'auhtor' TEXT, 'borrowed' BOOLEAN);

----
-- Data dump for books, a total of 0 rows
----
COMMIT;
