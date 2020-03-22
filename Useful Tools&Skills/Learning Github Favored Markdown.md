# Learning Github Favored Markdown

## Suggestions

I made the guide while reading other tutorials. **Making a markdown article by yourself** boosts your speed of mastering markdown.

## Markdown Editors

- **VS Code** —— Provides friendly environment for programmers.
- **Typora** —— Instantly display the effect of your code.
- Find More Editors —— [SSpai's Rcommendation](https://sspai.com/post/42126)

## Basic Syntax 

### File extension

 `.md` `.markdown` `.md` `.mmdown`

### Ignoring Markdown Formatting

- Just use `\` before the character you want to ignore. 
- One `\` ignores one character.
- For eg, using `\*\*Message` to print `*\*Message`.

### Texts

#### Plain Text

`Plain text does not require any non-alphabetical characters`

#### Bold Text

`**[Text]**` will convert [Text] to **[Text]**

`__Text__	(2 underline each side) makes the same effect`

#### Italic Text

`*[Word]*` will make the [word] as *italic* as *word*

`_Word_ (1 underline each side) does the same thing.`

#### Text with strikethrough

```markdown
~~Text~~ will appear crossed out.
```

~~For example~~

#### Headers

`Typing "## Text" will make a header. The number of "#" determines its size.The more # you type, the smaller the header will be.`

`Headers with one # is called <h1> headers, the maximum number of # is 6, which defines an <h6> header with "###### Header"`

#### Paragraphs

`Leaving an empty line will create a new paragraph.`

### Lists

#### Unordered lists

```markdown
* Item1
	*Item 1.1
```

These two lines can make an unordered list below(Square dot):

* Item1
  * Item1.1

You can also replace **`*`** with **`-`**

On some desktop editors(Like Typora), pressing **`Tab`** will make a sub-list, while pressing **`Enter`** makes the cursor back to the upper level directory. Directly pressing **`Backspace`** will jump to the previous line.

####  Ordered Lists

 ```markdown
1. Item 1
3. Item 2
	1.Item 2.1
 ```

Just replace the **`*`**with the number you want.

#### Task Lists (Github Favored)

```markdown
- [x] Task 1 is complete.
- [ ] Task 2 is incomplete.
```

Results:

- [x] Task 1 is complete.
- [ ] Task 2 is incomplete.

In Github, if a task list item description begins with a parenthesis, you'll need to escape it with `\`:

```markdown
- [ ] \(Optional) Open a followup issue
```

### Tables(Github Favored)

```markdown
Header 1 | Header 2 | Header 3
-------- | ------ |--------
Content 1 | Content 2 | Content 3
Content 4 and content 5 | Content 6 | Content 7
```

Results:

| Header 1                | Header 2  | Header 3  |
| ----------------------- | --------- | --------- |
| Content 1               | Content 2 | Content 3 |
| Content 4 and content 5 | Content 6 | Content 7 |

------------------------------------------------------------

- Hyphens `-` divide the headers and contents. 

- In fact, you needn't try to make the hyphens as wide as the headers. This trick works well with most of the editors.

### Divide Lines

```markdown
--- makes a divide line.
You can type more,like ------------------------
```

### Links

```markdown
[The title of the link](https://with.the.url)
```

You can also add a **relative link** in GitHub repo.

For eg:

```markdown
[This Link](folder/file.md) ,links to file.md in a directory called folder, while the directory called folder is located in the root directory.

Relative link operands are also availiable, such as ./ and ../
```

[This is the link of my blog.](https://codeword.info)

- Github automatically converts URLs into a real link.

### Images

```markdown
To insert an internal image,type:
![Comments of the image](url)

You can omit the domain when inserting an internal url.
eg. ![Image](/internal/iamge.webp)
```

### Quotes

```markdown
> Quote things here
```

Result:

> Quote things here

- Pressing **`Enter`** twice to jump to the next line and exit the Quote Mode.

### Code

```markdown
​```[The language of the code]
start
print: Hello world!
exit
​```

PS: ``` can be replaced with ~~~ or [four spaces]
```

### Combined Syntax

Below are the syntax table from [Github](https://help.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax#styling-text), it summarized the styling of text as well as provided a good example of combined syntax.

| Style                  | Syntax             | Keyboard shortcut   | Example                                  | Output                                   |
| ---------------------- | ------------------ | ------------------- | ---------------------------------------- | ---------------------------------------- |
| Bold                   | `** **` or `__ __` | command/control + b | `**This is bold text**`                  | **This is bold text**                    |
| Italic                 | `* *` or `_ _`     | command/control + i | `*This text is italicized*`              | *This text is italicized*                |
| Strikethrough          | `~~ ~~`            |                     | `~~This was mistaken text~~`             | ~~This was mistaken text~~               |
| Bold and nested italic | `** **` and `_ _`  |                     | `**This text is _extremely_ important**` | **This text is \*extremely\* important** |
| All bold and italic    | `*** ***`          |                     | `***All this text is important***`       | ***All this text is important\***        |

### Inline Code

```markdown
`<Your own HTML code or elements>`
```

### Other Github Favored Syntax

#### SHA Reference

```markdown
16c999e8c71134401a78d4d46435517b2271d6ac
mojombo@16c999e8c71134401a78d4d46435517b2271d6ac
mojombo/github-flavored-markdown@16c999e8c71134401a78d4d46435517b2271d6ac
```

#### Issue Reference within a repo

```markdown
#1
mojombo#1
mojombo/github-flavored-markdown#1

1 is the number of the issue or pull request.
```

#### Mentions

```markdown
@username
@team_name (within an organization)
```

#### Emojis

Checkout the [Emoji Cheat Sheet.](https://github.com/ikatyang/emoji-cheat-sheet/blob/master/README.md)

#### [Content attachments](https://help.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax#content-attachments)

Some GitHub Apps provide information in GitHub for URLs that link to their registered domains. GitHub renders the information provided by the app under the URL in the body or comment of an issue or pull request.



































