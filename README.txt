[Getting Started]

Step 1: Find a *.txt file that lists all (or close to all) English words. You can find a lot of those online because just about every novice programmer like me ends up coding something related to English words.
The text file must be in ALL LOWERCASE (ironic how I wrote that in all uppercase), and each word must be on a NEW LINE.

Step 2: Name that text file 'words.txt' (verbatim) and place it in the program directory (so in the same folder as the *.exe file).

And that's about it...
---------------------------
[How to use the program]

Prompt 1: Enter pattern

Suppose that you know the word has 5 letters, then you just type in 5 underscores ('_____') so that the app gives you all the words with 5 letters.
But let's say that you know the word has 5 letters, but the first letter is 't'; then you type in 't____' ('t' followed by 4 underscores).
Basically underscores signify spaces that any letter can occupy.
If you know where a letter is supposed to be, then, well, put that letter there.

Ex. You're looking for a 7 letter word where the first 3 letters are 'w' 'e' and 'l'.
Type in: 'wel____' ('wel' followed by 4 underscores because 3 + 4 = 7)

Prompt 2: Enter exclusion pattern

So let's assume that you're looking for a 10 letter word, but it absolutely CANNOT end with an 'er'.
Then you just type in '________er' (8 underscores followed by 'er' because 8 + 2 = 10).
So the underscores signify that any letter can occupy those places, but the 'er' at the end tells the app to ignore anything with the last two letters as 'e' and 'r'.

Ex. You're looking for a 5 letter word where the second letter CANNOT be 'a'.
For Prompt 1, you type in '_____' (5 underscores) since you want to search the list of all the 5-lettered words.
For Prompt 2, you type in '_a___' since you want to exclude the 5-lettered words whose second letter is 'a'.

Prompt 3: What letters does the word contain?

Just string all the letters together. If the word contains 'a', 'b', 'c', and 'w', type in 'abcw'.

Prompt 4: What letters does the word NOT contain?

Same thing as prompt 3. If the word does NOT contain 'a', 'b', 'c', and 'w', type in 'abcw'.

Make sure the inputs do not contradict each other!
If you don't want to answer a prompt, just hit Enter to skip it.
--------------------------------------------------------------------
[Error Messages]

"Failed to load word list... Check README.txt for help."

Read the [Getting Started] section again because you might've missed something.
------------------------------------------------------------------------------------
[Full Example]

You're playing Wordle and you know that a word contains the letters 'l' and 'p', but doesn't contain the letters 'a', 'b', and 'g'. You also know that the word doesn't end with an 'l' and then a 'p', and that the word begins with a 'w'.

Prompt 1: You type in 'w____' ('w' then 4 underscores) since you want to search the entire list of 5-lettered words that start with 'w'.
Prompt 2: You type in '___lp' (3 underscores then 'lp') since you want to exclude anything that ends with an 'lp'
Prompt 3: You type in 'lp' since you KNOW that there is an 'l' and a 'p'... the word just doesn't end with it.
Prompt 4: You type in 'abg' since you know 'a', 'b', and 'g' aren't in the word.

FYI: I don't think there is any word that satisfies these requirements...