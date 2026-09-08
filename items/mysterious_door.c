/* file: items/mysterious_door.c */
inherit DOOR;

void setup(string direction, string destination)
{
	set_id("door");
	set_adj("mysterious", "wooden");

	set_long(
		"The mysterious wooden door hints at riches and mystery within."
	);

	set_sibling_ident("zayaville mysterious door");
	set_door_direction(direction);
	set_door_destination(destination);
	set_closed(1);
	set_locked("mysterious room key");

	set_flag(ATTACHED);

}

/* makes the door visible when closed */
void do_on_close()
{
  ::do_on_close();
  set_hidden(0);
}