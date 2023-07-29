-- Keep a log of any SQL queries you execute as you solve the mystery you solve
select receiver from phone_calls where caller = "(367) 555-5533" and day = 28 and month = 7;
SELECT description FROM crime_scene_reports WHERE AND month = 7 AND day = 28 AND street = 'Humphrey Street';
SELECT name, transcripts FROM interviews WHERE AND month = 7 AND day = 28;
SELECT account_number, amount FROM atm_transactions WHERE AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
select flights.id,airports.city,passengers.passport_number,flights.day,flights.hour,flights.minute,flights.month,flights.year from  flights join airports on airports.id = flights.destination_airport_id join passengers on passengers.flight_id = flights.id where passengers.passport_number = 5773159633 or passengers.passport_number = 3592750733;
select  flights.id,airports.city from flights join airports on airports.id = flights.destination_airport_id where day = 26 and month = 7;
select airports.city from flights join airports on airports.id = flights.origin_airport_id where day = 26 and month = 7;
select abbreviation,full_name,city from airports;
select caller,id from phone_calls where id = 221 or id = 224 or id = 233 or id = 234 or id = 251 or id = 251 or id = 254 or id = 255 or id = 261 or id = 279 or id = 281 ;
select caller,id from phone_calls where day = 28 and month = 7;
select license_plate from bakery_security_logs where id > 259 and id < 268;
select person_id,people.name,people.phone_number,people.passport_number,people.license_plate,people.id from bank_accounts join people on bank_accounts.person_id = people.id where account_number = 28500762 or account_number = 28296815 or account_number = 76054385 sqlite>  or account_number = 49610011 or account_number = 16153065 or account_number = 25506511 or account_number = 81061156;
