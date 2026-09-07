void setup() 
{
	/* Descriptive room text */
	set_area("zayaville");

	set_brief("Simple Village Road");

	set_long(
		"This is a simple road leading to a simple village. There is "
		"very little of any excitement about it, except that it represents "
		"your first steps toward becoming a creator!"
	);

	set_weather(1);

	/* Add any "discoverable" items here. */
	add_item(
		"village",
		"The village is simple, but beautiful because of it."
	);

	add_item(
		"road",
		"The road passes beneath you on its way toward the village."
	);

	/* Navigate to a second room */
	set_exits(([
	"northeast" : "street_02",
	]));

}
