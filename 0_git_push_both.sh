git config --global user.email tomxue0126@gmail.com
git config remote.origin.url git@github.com:tomxue/FIFO_read_write.git
git push origin --mirror

echo ""
git config --global user.email tomxue@outlook.com
git config remote.origin.url ssh://tomxue@45.78.43.18:29418/0_Linux/UserSpace/IPC/FIFO_read_write.git
git push origin --mirror

echo ""
git config -l | grep url
git config -l | grep email
