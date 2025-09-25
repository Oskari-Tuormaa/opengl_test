local nmap = require("config.utils").nmap

nmap("<leader>e", "<cmd>sp term://cmake --build build -j<cr>")
nmap("<leader>E", "<cmd>sp term://cmake --build build -j && build/opengl<cr>")
nmap("<leader>bp", "<cmd>sp term://cmake --fresh -B build -G Ninja<cr>")
