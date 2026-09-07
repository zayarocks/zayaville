inherit ADVERSARY;

// idle 
inherit M_ACTIONS;

void setup()
{
	::setup();

	set_name("beefy");
	add_id("captain");

	set_proper_name("Captain Beefy");
	set_in_room_desc("Captain Beefy stands here, looking nervous.");

	set_long(
		"Captain Beefy is a former military officer who retired after being "
		"stabbed in the face by a marauding adventurer. He now lives in "
		"Zayaville, hoping to enjoy a quiet life before someone murders him "
		"for his shoes."
	);

	set_gender(1);
	set_level(10);

	set_actions(
		10,
		({
			"say Please don't hurt me.",
			"cower",
			"say Here come the drums!",
			"stare",
		})
	);
	
}
