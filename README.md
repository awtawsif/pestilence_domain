# Pestilence Domain

A dark, atmospheric text-based adventure game written in C where players navigate through plague-infested marshes and make moral choices that shape their journey.

## Synopsis

You encounter Pestilence in the Infested Marshes, who offers you three paths of corruption to choose from:
- **Flesh** - The Rot That Breathes
- **Faith** - The Prayer of the Diseased  
- **Thought** - The Whispering Fog

Each path presents moral dilemmas and consequences that test your character and determine your fate.

## Building

```bash
gcc -o pestilence main.c output.c flesh.c faith.c thought.c choose.c
```

## Running

```bash
./pestilence
```

## Structure

- `main.c` - Entry point and main game loop
- `output.c/h` - Terminal output formatting and colors
- `flesh.c/h` - Flesh path storyline
- `faith.c/h` - Faith path storyline  
- `thought.c/h` - Thought path storyline
- `choose.c/h` - Player choice handling
- `colors.h` - Color definitions for terminal output