/* file: items/mysterious_key.c */
inherit KEY;

void setup()
{
  set_id("key");
  set_adj("small", "brass", "mysterious");

  set_in_room_desc("A small brass key has been left here.");

  set_long(
    "This is a small brass key. A question mark is engraved on its bow."
  );

  set_key_type("mysterious room key");
  set_mass(0.1);
  set_value(25);
}