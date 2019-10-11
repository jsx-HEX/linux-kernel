# git
### push步骤
0. 在本地仓库修改（添加文件、删除、）
1. 使用`git add/rm ./filename`命令修改暂存区
2. 使用`git commit [选项] "注释内容"` 提交修改到本地仓库
3. 使用`git push`命令同步远程仓库

### pull
0. 远程仓库可能被修改
1. `git fetch origin master`
2. `git log -p master...origin/master` 查看远程仓库与本地仓库差别
3. `git merge origin/master` 合并远程仓库到本地

# vim
1. 不正常退出会产生名为 .filename.swp 隐藏文件，再次进入文件会异常，可使用rm命令删除.filename.swp文件。之后可再进入原文件，但是未保存的修改会丢失
