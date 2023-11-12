<!--
 * @Description: Copyright 2020 Tencent Inc.  All rights reserved.
-->

# 说明

- stage0: 原始编译
- stage1~4: bazel构建

```shell
bazel build //main:hello-world
```

## Stage4

```shell
bazel test --cxxopt=-std=c++14 --test_output=all //main:greet-test
```

# 插件

- C/C++
- C/C++ Runner
- KoroFileHeader
- bazel

`settings.json`中`args`下指定标准库版本:
```
"-std=c++17",
"-stdlib=libc++"
```

`clang-format`:
```
{ BasedOnStyle: WebKit, IndentWidth: 4, IndentCaseLabels: false, UseTab: Never, BreakBeforeBraces: Attach, AllowShortIfStatementsOnASingleLine: true, PointerAlignment: Left}
```

# 参考

[MacOs+vscode配置c++编译环境]: https://zhuanlan.zhihu.com/p/640266153
[cland导致跳转功能失败]: 这坑爹玩意儿--https://blog.csdn.net/smicd/article/details/130768871
[SFTP]: 同步代码到服务器，查看插件说明，配置ssh密钥免密登录
[bazel]: https://bazel.build/tutorials/cpp-use-cases?hl=zh-cn
[bazel C++ 构建教程]: https://bazel.build/start/cpp?hl=zh-cn 
[bazel C++ examples]: https://github.com/bazelbuild/examples
[bazel C++ 规则]: https://bazel.build/reference/be/c-cpp?hl=zh-cn#cc_library
[bazel 外部依赖项]: https://bazel.build/external/advanced?hl=zh-cn
[bazel API]: https://bazel.build/rules/lib/overview?hl=zh-cn
[bazel BUILD examples]: https://blog.csdn.net/A_L_A_N/article/details/88018718
[GoogleTest C++单测]: https://github.com/google/googletest
[GoogleTest Tutorial]: https://google.github.io/googletest/
[vscode格式化C++配置]: https://km.woa.com/articles/show/399467?kmref=search&from_page=1&no=2
