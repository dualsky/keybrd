How to Contribute
=================
We'd love for you to contribute to our source code, review pull requests, and take part in discussions.

The Keybrd community is made up of users in different roles:
* **Owner** is the user that has the project on their account.
* **Contributors** is everyone who has had a pull request merged into a project.
* **Reviewers** are the users who review pull requests and take part in discussions.

## Submitting a Pull Request
Pull Request is the preferred way to contribute code.
If you want to contribute code some other way, please ask in the [todo: geekhack thread](URL).

The GitHub pull request discussion process is fluid and very flexible.
For simple changes, the contributor can push the change with the initial Change Request and a discussion may or may not follow.
For complex changes, the contributor may push a patch after some discussion and continue pushing patches and updating the Change Request as the discussion evolves.

Here are a few items that will make the pull request process go smoothly:

### Getting Started with GitHub, Git, and .gitignore
Contributors need to fork, clone, push, fetch, and submit pull requests.
A good place to learn these is [boot camp](https://help.github.com/categories/bootcamp/).

You will also need [Teensyduino + Arduino IDE](doc/keybrd_library_user_guide.md#getting-started-with-teensy20-arduino-ide-and-keybrd) and [Git](http://git-scm.com/downloads) installed on your computer.

The local .gitignore file whitelists the keybrd_sketches and keybrd directories.
Put patterns of your editor's generated temporary files in [.gitignore_global]( https://help.github.com/articles/ignoring-files/#create-a-global-gitignore).

### Change Request
Change Request is a proposal for altering the keybrd library.
It should contain: title, description, and why the change is valuable.
The Contributor maintains Change Request in the first comment for the life of the pull request.

Change Request template:
```
# Change Request
<description of change>

<how it is useful, if not obviouse from the descrption>
```
### Consistent Style
Follow the style guide and naming conventions in [keybrd Library Developer's Guide](doc/keybrd_library_developer_guide.md).

### Good Commit Messages
There are only two formatting rules for commit messages:
* All lines should be 78 characters of less. This is for terminals, which don't automatically line wrap.
* There should be a one-line summary, then an empty line, followed by the body of the commit message.

Commit Message template:
```
<one-line summary>

<body of commit message>
```

Content of a thorough commit message:
* Describe what the commit does.
* If commit fixes an issue, link to that issue.
* If commit adds a new feature, include a concrete use case example.
* Use the imperative, present tense ('change', not 'changed' or 'changes').
* Sometimes a bulleted list is a good format to convey the changes of a commit.

## Reviewing a Pull Request
Coding is only half the battle in software development.
Our code also has to be thoroughly reviewed before release.
Reviewers are thus an integral part of the development process.

Feel free to view any open pull request.
Each pull request contains tabs for Conversation, Commits, and Files changed.
There are two different kinds of review:
* proof reading the documentation or reading code for logic errors
* manual testing (suggestions for automating keyboard firmware testing are welcome)

Chose which ever type of review suites your interest and skill level.

You will need a [GitHub](https://github.com/signup/free) account to leave comments.
The owner waits at least 24 hours from last topic branch push to give reviewers time to comment.

### Reading Documentation and Code
Reading can be done from the pull request **Commits** tab or **Files changed** tab.
If a problem is found, click the line number containing the error and leave a comment.

### Manual Testing on Keyboards
Manual testing requires a keyboard testing environment:
* appropriate microcontroller installed in keyboard
* Arduino IDE installed on computer

Once the testing environment is setup, download the code and start testing it:

1. fetch topic branch from pull requester (Contributor)
2. compile and load firmware onto keyboard's microcontroller
3. manually type on the keyboard

If a problem is found, notify the author by commenting in the pull request.
