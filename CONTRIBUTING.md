

# Contributing to Wase Engine

<!-- This CONTRIBUTING.md is adapted from https://gist.github.com/peterdesmet/e90a1b0dc17af6c12daf6e8b2f044e7c -->

First of all, thanks for considering contributing to Wase Engine 👍!

Wase Engine is an open source project for me to learn more about game engine structures and contributing with other people.

[documentation]: https://wase-engine.com/documentation
[repo]: https://github.com/Wase-Engine/wase-engine
[issues]: https://github.com/Wase-Engine/wase-engine/issues
[new_issue]: https://github.com/Wase-Engine/wase-engine/issues/new/choose
[email]: info@wase-engine.com

## How you can contribute

There are several ways you can contribute to this project. If you want to know more about why and how to contribute to open source projects like this one, see this [Open Source Guide](https://opensource.guide/how-to-contribute/).

### Ask a question ⁉️

Using Wase Engine and got stuck? Browse the [documentation][documentation] to see if you can find a solution. Still stuck? Post your question as an [issue on GitHub][new_issue]. While we cannot offer user support, we'll try to do our best to address it, as questions often lead to better documentation or the discovery of bugs.

Want to ask a question in private? Contact me by [email](mailto:email).

### Propose an idea 💡

Have an idea for a new Wase Engine feature? Take a look at the [documentation][documentation] and [issue list][issues] to see if it isn't included or suggested yet. If not, suggest your idea as an [issue][new_issue]. While we can't promise to implement your idea, it helps to:

* Explain in detail how it would work.
* Keep the scope as narrow as possible.

See below if you want to contribute code for your idea as well.

### Report a bug 🐛

Using Wase Engine and discovered a bug? That's annoying! Don't let others have the same experience and report it as an [issue][new_issue] so we can fix it. A good bug report makes it easier for us to do so, so please include:

* Your operating system name and version (e.g. Mac OS 10.13.6).
* Detailed steps to reproduce the bug.
* Any other details about your local setup that might be helpful in troubleshooting.

### Improve the documentation 📖

Noticed a typo in the [documentation](https://wase-engine.com/documentation)? Think a function could use a better example? Good documentation makes all the difference, so your help to improve it is very welcome!
In the [documentation repository](https://wase-engine.com/documentation) you can add documentation or make changes. This will be automatically be updated on the website.

### Contribute code 📝

Care to fix bugs or implement new functionality to Wase Engine? Awesome 👏! Have a look at the [issue list][issues] and leave a comment on the things you want to work on. See also the development guidelines below.

## Development guidelines

We try to follow the [GitHub flow](https://guides.github.com/introduction/flow/) for development.

1. Fork [this repo][repo] and clone it to your computer. To learn more about this process, see [this guide](https://guides.github.com/activities/forking/).
2. If you have forked and cloned the project before and it has been a while since you worked on it, [pull changes from the original repo](https://help.github.com/articles/merging-an-upstream-repository-into-your-fork/) to your clone by using `git pull upstream master`.
3. Set up the project with cmake.
4. Make your changes:
    * Write your code.
    * Test your code (it should not include any memory leaks).
    * Write unit tests if possible for your code
    * Update the CMakeLists.txt
5. Commit and push your changes.
6. Submit a [pull request](https://guides.github.com/activities/forking/#making-a-pull-request).
