/* file: chars/joe.c */
inherit ADVERSARY;
inherit M_VENDOR;
inherit M_ACTIONS;

void setup()
{
	::setup();

	set_name("joe");
	add_id("stabby", "shopkeeper");

	set_proper_name("Stabby Joe");
	set_in_room_desc("Stabby Joe stands behind the counter.");

	set_long(
		"This is Stabby Joe, Zayaville's main shopkeeper and... well, "
		"let's just say that he has some anger issues. While generally at "
		"peace, he can be riled into fits of towering rage by any mention "
		"of his cousin, Slicey Pete."
	);

	set_gender(1);
	set_race("human");
	set_level(15);

	set_actions(
		10,
		({
			"say Buy my stuff, or I'll kill you.",
			"say Good prices on all my stuff!",
			"say Satisfaction guaranteed, or I'll kill you!",
		})
	);

	set_currency_type("gold");
	set_for_sale(1);
	set_will_buy(0);

	set_sell(([
		"^std/weapon/sword"               : 3,
		__DIR__ "../items/mysterious_key" : 1,
	]));
}