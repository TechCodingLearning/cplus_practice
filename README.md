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
Google
```
```
{ BasedOnStyle: WebKit, IndentWidth: 4, IndentCaseLabels: false, UseTab: Never, BreakBeforeBraces: Attach, AllowShortIfStatementsOnASingleLine: true, PointerAlignment: Left}
```

`snipptes`:
```
{
	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	// "Print to console": {
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
    "C C++ Header": {
        "scope": "c, cpp",
        "prefix": "hd", // 快捷键
        "description": "Add #ifndef, #define and #endif",

        "body": [
            "#ifndef ${RELATIVE_FILEPATH/([^a-zA-Z0-9])|([a-zA-Z0-9])/${1:+_}${2:/upcase}/g}_",
            "#define ${RELATIVE_FILEPATH/([^a-zA-Z0-9])|([a-zA-Z0-9])/${1:+_}${2:/upcase}/g}_",
            "",
            "$0",
            "",
            "#endif // ${RELATIVE_FILEPATH/([^a-zA-Z0-9])|([a-zA-Z0-9])/${1:+_}${2:/upcase}/g}_",
            ""
        ]
    },
    "C C++ namespace": {
        "scope": "c, cpp",
        "prefix": "ns", // 快捷键
        "description": "Add namespace",

        "body": [
            "namespace ${TM_SELECTED_TEXT/(.*)/${1:/lowcase}/} {",
            "$0",
            "",
            "} // namespace ${TM_SELECTED_TEXT/(.*)/${1:/lowcase}/}",
            ""
        ]
    }
}
```

# 参考

MacOs+vscode配置c++编译环境: https://zhuanlan.zhihu.com/p/640266153
cland导致跳转功能失败: 这坑爹玩意儿--https://blog.csdn.net/smicd/article/details/130768871
SFTP: 同步代码到服务器，查看插件说明，配置ssh密钥免密登录
bazel安装: https://bazel.build/versions/6.4.0/install/redhat
bazel: https://bazel.build/tutorials/cpp-use-cases?hl=zh-cn
bazel C++ 构建教程: https://bazel.build/start/cpp?hl=zh-cn 
bazel C++ examples: https://github.com/bazelbuild/examples
bazel C++ 规则: https://bazel.build/reference/be/c-cpp?hl=zh-cn#cc_library
bazel 外部依赖项: https://bazel.build/external/advanced?hl=zh-cn
bazel API: https://bazel.build/rules/lib/overview?hl=zh-cn
bazel BUILD examples: https://blog.csdn.net/A_L_A_N/article/details/88018718
GoogleTest C++单测: https://github.com/google/googletest
GoogleTest Tutorial: https://google.github.io/googletest/
Snippets: https://code.visualstudio.com/docs/editor/userdefinedsnippets
