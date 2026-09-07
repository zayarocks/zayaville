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
	  "north"     : "market_northwest",
	  "east"      : "market_southeast",
	  "west"      : "street_03",
	  "northeast" : "market_northeast",
	]));

}
