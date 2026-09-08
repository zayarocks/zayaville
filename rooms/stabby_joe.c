/* file: rooms/stabby_joe.c */
inherit INDOOR_ROOM;

void setup()
{
	set_area("zayaville");

	set_brief("Stabby Joe's Emporium of Wonder");

	set_long(
		"This is Stabby Joe's Emporium of Wonder, where he sells "
		"wonderful things. He also stabs people."
	);

	add_item(
		"emporium", "shop",
		"The emporium is packed with strange and wonderful merchandise."
	);

	set_objects(([
		"../chars/joe" : 1,
	]));

	set_exits(([
		"south" : "market_northeast",
	]));
}