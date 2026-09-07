inherit INDOOR_ROOM;

void setup()
{
  set_area("zayaville");

  set_brief("Mysterious Room");

  set_long(
    "This is a mysterious room. The oppressive atmosphere hints "
    "mysteriously at some deeper mystery."
  );

  add_item(
    "mystery",
    "You cannot see the mystery, which only makes it more mysterious."
  );

  add_item(
    "darkness",
    "The darkness seems almost independent of the room's actual lighting."
  );

  set_listen(
    "The room emits a faint and deeply mysterious hum."
  );

  set_exits(([
    "south" : "market_northwest",
  ]));
}