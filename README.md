# Zayaville
Zayaville is a very basic mudlib running on FluffOS. hHighly inspired by the LPC for Dummies books by Drakkos. In fact, all of the code is more or less identical, just with the word "Zaya" all over it. (Clever, isn't it?)

All files reside in the domain folder located at ``lib/domain/zayaville``. If you don't want to live in Zayaville, make whatever 'ville you'd like. 

## Book 1
This guide assumes a certain proficiency at Unix administration and programming in C. However, the book itself 

### My First Room

### rooms/street_01.c
Edit rooms/street_01.c. The following code demonstrates how to set the initial descriptive text for the room, as well as the weather and any items. 
*The active working directory should be your personal domain folder.*

```c
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
```

### rooms/street_02.c
This second room is needed to make the exit functional. 
```c
inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");

  set_brief("Simple Village Road");

  set_long(
    "This is a little way along the path to the village of "
    "Zayaville. The path continues northeast toward the rickety "
    "buildings of the market square. To the southwest, the path "
    "winds away from what passes as civilization here."
  );

  set_weather(1);

  set_exits(([
    "southwest" : "street_01",
  ]));
}
```


To see the updated room, run the following commands on the MUD:
```bash
update rooms/street_01.c
goto rooms/street_01.c
look
look at village
look at road
```

Not all nouns from the description need to be actual items in the room. However, doing so certainly helps with immersion. 




### My First Area
```
```

### Building The Perfect Beast
```
```

### Hooking Up
```
```

### Back To The Beginning
```
```

### Now That We're An Item
```
```

### An Inside Job
```
```

### Dysfunctional Behavior
```
```

### Going Loopy
```
```

### Arrays, You say?
```
```

### Hooray for Arrays
```
```

### Mapping It Out
```
```

### So Long
```
```
