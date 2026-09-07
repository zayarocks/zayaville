# Zayaville
Zayaville is a very basic mudlib running on FluffOS. hHighly inspired by the LPC for Dummies books by Drakkos. In fact, all of the code is more or less identical, just with the word "Zaya" all over it. (Clever, isn't it?)

All files reside in the domain folder located at ``lib/domain/zayaville``. If you don't want to live in Zayaville, make whatever 'ville you'd like. 

## Book 1
This guide assumes a certain proficiency at Unix administration and programming in C. However, the book itself 

### My First Room
Edit rooms/street_01.c.

```
inherit OUTDOOR_ROOM;

void setup()
{
    set_area("zayaville");

    set_brief("Simple Village Road");

    set_long(
        "This is a simple road leading to a simple village. There is "
        "very little of any excitement about it, except that it represents "
        "your first steps toward becoming a creator!"
    );

    set_weather(1);
}
```

To see the updated room, run the following commands on the MUD:
```bash
update rooms/street_01.c
goto rooms/street_01.c
```
*Make sure that you are in the proper working directory.*


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
