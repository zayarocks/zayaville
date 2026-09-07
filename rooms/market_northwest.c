inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");

  set_brief("Northwest Corner of Zayaville Marketplace");

	set_long(
	  "The northwest corner of Zayaville's cobblestone marketplace lies "
	  "between a row of weathered buildings. The marketplace continues "
	  "south and east."
	);

	set_exits(([
	  "south"     : "market_southwest",
	  "east"      : "market_northeast",
	  "southeast" : "market_southeast",
	]));

	set_objects(([
	  "../items/mysterious_door" : ({ "north", "mysterious_room" }),
	]));

}
