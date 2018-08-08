# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

"An artificial long word said to mean a lung disease caused by inhaling very fine ash and sand dust."

## According to its man page, what does `getrusage` do?

`getrusage` returns resource usage measures for who.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

We pass `before` and `after` by reference to the function `calculate` because passing large structs by value is slow. Passing by value to `calculate` will go to the stack, which could potentially cause stack overflow.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The key in the `for` loop is the `int c = fgetc(file); c != EOF; c = fgetc(file)` which reads through the entire text file. Essentially `c` is the letter of the word and the `for` loop goes through each letter of the word while checking for conditions. These conditions are to allow only alphabetical characters and apostrophe and also ignoring words with numbers in them. The `index` is the length of the word and within the conditions, the rest of the alphabetical string is consumed, if it matches the condition. Once this process is done and the condition of the word is not an alpanumeric or a number, then the word is complete. Signaling `word[index] = '\0'` would terminate the word, spell check it and start a new word. The `index` is then reset to 0 to denote a new word.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

Using `fgetc` is not error prone because you want to check each individual characters for conditions (such as making sure it's alphanumeric, ignore digits, etc.) of the string. `fscanf` would read them and may potentially cause errors.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

These parameters are declared as `const` because we don't want the dictionary or word to be changed during the process of loading the dictionary and checking each word.
