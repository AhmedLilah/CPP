-- Read the docs: https://www.lunarvim.org/docs/configuration
-- Video Tutorials: https://www.youtube.com/watch?v=sFA9kX-Ud_c&list=PLhoH5vyxr6QqGu0i7tt_XoVK9v-KvZ3m6
-- Forum: https://www.reddit.com/r/lunarvim/
-- Discord: https://discord.com/invite/Xb9B4Ny

-- Enable powershell as your default shell
vim.opt.shell = "pwsh.exe -NoLogo"
vim.opt.shellcmdflag =
"-NoLogo -NoProfile -ExecutionPolicy RemoteSigned -Command [Console]::InputEncoding=[Console]::OutputEncoding=[System.Text.Encoding]::UTF8;"
vim.cmd [[
                let &shellredir = '2>&1 | Out-File -Encoding UTF8 %s; exit $LastExitCode'
                let &shellpipe = '2>&1 | Out-File -Encoding UTF8 %s; exit $LastExitCode'
                set shellquote= shellxquote=
                ]]

-- Set a compatible clipboard manager
vim.g.clipboard = {
        copy = {
                ["+"] = "win32yank.exe -i --crlf",
                ["*"] = "win32yank.exe -i --crlf",
        },
        paste = {
                ["+"] = "win32yank.exe -o --lf",
                ["*"] = "win32yank.exe -o --lf",
        },
}

vim.opt.tabstop = 8
vim.opt.softtabstop = 8
vim.opt.shiftwidth = 8
vim.opt.number = true
vim.opt.numberwidth = 1
vim.opt.relativenumber = true
vim.opt.wrap = true
vim.opt.wrapmargin = 50
vim.opt.wrapscan = true
vim.opt.textwidth = 0
vim.opt.breakindent = true
vim.opt.breakindentopt= "shift:" .. vim.opt.tabstop:get()
vim.opt.linebreak = false
lvim.transparent_window = true

lvim.plugins = {
        {"Mofiqul/dracula.nvim",
                config = function()
                        require("dracula").setup({
                                -- customize dracula color palette
                                --         -- #0f9241 string Green
                                --         -- #0dc084 Types Green
                                --         -- #c062ca Macro Purple
                                --         -- #1e1e1e Background Dark-Gray
                                --         -- #569cd6 Keywords Blue
                                --         -- #ffff80 Numbers Yellow
                                colors = {
                                        bg = "#282A36",
                                        fg = "#F8F8F2",
                                        selection = "#44475A",
                                        comment = "#6272A4",
                                        red = "#FF5555",
                                        orange = "#FFB86C",
                                        yellow = "#F1FA8C",
                                        green = "#50fa7b",
                                        purple = "#BD93F9",
                                        cyan = "#8BE9FD",
                                        pink = "#FF79C6",
                                        bright_red = "#FF6E6E",
                                        bright_green = "#69FF94",
                                        bright_yellow = "#FFFFA5",
                                        bright_blue = "#D6ACFF",
                                        bright_magenta = "#FF92DF",
                                        bright_cyan = "#A4FFFF",
                                        bright_white = "#FFFFFF",
                                        menu = "#21222C",
                                        visual = "#3E4452",
                                        gutter_fg = "#4B5263",
                                        nontext = "#3B4048",
                                        white = "#ABB2BF",
                                        black = "#191A21",
                                },
                                -- show the '~' characters after the end of buffers
                                show_end_of_buffer = true, -- default false
                                -- use transparent background
                                -- transparent_bg = false, -- default false
                                -- set custom lualine background color
                                -- lualine_bg_color = "#282A36", -- default nil
                                -- set italic comment
                                italic_comment = true, -- default false
                                -- set italics
                                dracula_italic = true, -- default false

                        })
                end
        },

        {"sineto/fzy.nvim"},

        -- peeks the lines we are going to using :{line-number} before we go.
        {
                "nacro90/numb.nvim",
                event = "BufRead",
                config = function()
                        require("numb").setup {
                                show_numbers = true, -- Enable 'number' for the window while peeking
                                show_cursorline = true, -- Enable 'cursorline' for the window while peeking
                        }
                end,
        },

        -- better quick fix window
        {
                "kevinhwang91/nvim-bqf",
                event = { "BufRead", "BufNew" },
                config = function()
                        require("bqf").setup({
                                auto_enable = true,
                                preview = {
                                        win_height = 12,
                                        win_vheight = 12,
                                        delay_syntax = 80,
                                        border_chars = { "┃", "┃", "━", "━", "┏", "┓", "┗", "┛", "█" },
                                },
                                func_map = {
                                        vsplit = "",
                                        ptogglemode = "z,",
                                        stoggleup = "",
                                },
                                filter = {
                                        fzf = {
                                                action_for = { ["ctrl-s"] = "split" },
                                                extra_opts = { "--bind", "ctrl-o:toggle-all", "--prompt", "> " },
                                        },
                                },
                        })
                end,
        },

        -- rainbow parentheses
        {
                "mrjones2014/nvim-ts-rainbow",
        },

        -- shows the current function at the top of the screen when function doesn't fi the screen.
        {
                "romgrk/nvim-treesitter-context",
                config = function()
                        require("treesitter-context").setup{
                                enable = true, -- Enable this plugin (Can be enabled/disabled later via commands)
                                throttle = true, -- Throttles plugin updates (may improve performance)
                                max_lines = 0, -- How many lines the window should span. Values <= 0 mean no limit.
                                patterns = { -- Match patterns for TS nodes. These get wrapped to match at word boundaries.
                                        -- For all filetypes
                                        -- Note that setting an entry here replaces all other patterns for this entry.
                                        -- By setting the 'default' entry below, you can control which nodes you want to
                                        -- appear in the context window.
                                        default = {
                                                'class',
                                                'function',
                                                'method',
                                        },
                                },
                        }
                end
        },

        -- tabnine completion enginer for nvim-cmp
        {
                "tzachar/cmp-tabnine",
                build = "./install.sh",
                dependencies = "hrsh7th/nvim-cmp",
                event = "InsertEnter",
        },

        -- preview goto definition calls
        {
                "rmagatti/goto-preview",
                config = function()
                        require('goto-preview').setup {
                                width = 120; -- Width of the floating window
                                height = 25; -- Height of the floating window
                                default_mappings = false; -- Bind default mappings
                                debug = false; -- Print debug information
                                opacity = nil; -- 0-100 opacity level of the floating window where 100 is fully transparent.
                                post_open_hook = nil -- A function taking two arguments, a buffer and a window to be ran as a hook.
                                -- You can use "default_mappings = true" setup option
                                -- Or explicitly set keybindings
                                -- vim.cmd("nnoremap gpd <cmd>lua require('goto-preview').goto_preview_definition()<CR>")
                                -- vim.cmd("nnoremap gpi <cmd>lua require('goto-preview').goto_preview_implementation()<CR>")
                                -- vim.cmd("nnoremap gP <cmd>lua require('goto-preview').close_all_win()<CR>")
                        }
                end
        },

        -- function signature autocompletion
        {
                "ray-x/lsp_signature.nvim",
                event = "VeryLazy",
                opts = {},
                config = function(_, opts) require'lsp_signature'.setup(opts) end
        },
}

-- *** Plugins Enable/Editing Section ***
-- making dracula the default theme
lvim.colorscheme = "dracula"

local lsp_signature = require("lsp_signature")
-- Enable the plugin
lsp_signature.on_attach()
-- Configure the plugin (optional)
lsp_signature.setup({
        -- ... configuration options
})


local LSP_SIGNATURE_CFG = {
        debug = false, -- set to true to enable debug logging
        log_path = vim.fn.stdpath("cache") .. "/lsp_signature.log", -- log dir when debug is on
        -- default is  ~/.cache/nvim/lsp_signature.log
        verbose = false, -- show debug line number

        bind = true, -- This is mandatory, otherwise border config won't get registered.
        -- If you want to hook lspsaga or other signature handler, pls set to false
        doc_lines = 10, -- will show two lines of comment/doc(if there are more than two lines in doc, will be truncated);
        -- set to 0 if you DO NOT want any API comments be shown
        -- This setting only take effect in insert mode, it does not affect signature help in normal
        -- mode, 10 by default

        max_height = 12, -- max height of signature floating_window
        max_width = 80, -- max_width of signature floating_window, line will be wrapped if exceed max_width
        -- the value need >= 40
        wrap = true, -- allow doc/signature text wrap inside floating_window, useful if your lsp return doc/sig is too long
        floating_window = true, -- show hint in a floating window, set to false for virtual text only mode

        floating_window_above_cur_line = true, -- try to place the floating above the current line when possible Note:
        -- will set to true when fully tested, set to false will use whichever side has more space
        -- this setting will be helpful if you do not want the PUM and floating win overlap

        floating_window_off_x = 1, -- adjust float windows x position.
        -- can be either a number or function
        floating_window_off_y = 0, -- adjust float windows y position. e.g -2 move window up 2 lines; 2 move down 2 lines
        -- can be either number or function, see examples

        close_timeout = 4000, -- close floating window after ms when laster parameter is entered
        fix_pos = false,  -- set to true, the floating window will not auto-close until finish all parameters
        hint_enable = true, -- virtual hint enable
        hint_prefix = "🐼 ",  -- Panda for parameter, NOTE: for the terminal not support emoji, might crash
        hint_scheme = "String",
        hint_inline = function() return false end,  -- should the hint be inline(nvim 0.10 only)?  default false
        -- return true | 'inline' to show hint inline, return 'eol' to show hint at end of line, return false to disable
        -- return 'right_align' to display hint right aligned in the current line
        hi_parameter = "LspSignatureActiveParameter", -- how your parameter will be highlight
        handler_opts = {
                border = "rounded"   -- double, rounded, single, shadow, none, or a table of borders
        },

        always_trigger = false, -- sometime show signature on new line or in middle of parameter can be confusing, set it to false for #58

        auto_close_after = nil, -- autoclose signature float win after x sec, disabled if nil.
        extra_trigger_chars = {}, -- Array of extra characters that will trigger signature completion, e.g., {"(", ","}
        zindex = 200, -- by default it will be on top of all floating windows, set to <= 50 send it to bottom

        padding = '', -- character to pad on left and right of signature can be ' ', or '|'  etc

        transparency = nil, -- disabled by default, allow floating win transparent value 1~100
        shadow_blend = 36, -- if you using shadow as border use this set the opacity
        shadow_guibg = 'Black', -- if you using shadow as border use this set the color e.g. 'Green' or '#121315'
        timer_interval = 200, -- default timer check interval set to lower value if you want to reduce latency
        toggle_key = nil, -- toggle signature on and off in insert mode,  e.g. toggle_key = '<M-x>'
        toggle_key_flip_floatwin_setting = false, -- true: toggle floating_windows: true|false setting after toggle key pressed
        -- false: floating_windows setup will not change, toggle_key will pop up signature helper, but signature
        -- may not popup when typing depends on floating_window setting

        select_signature_key = nil, -- cycle to next signature, e.g. '<M-n>' function overloading
        move_cursor_key = nil, -- imap, use nvim_set_current_win to move cursor between current win and floating
}

-- recommended:
require'lsp_signature'.setup(LSP_SIGNATURE_CFG) -- no need to specify bufnr if you don't use toggle_key

-- You can also do this inside lsp on_attach
-- note: on_attach deprecated
-- require'lsp_signature'.on_attach(LSP_SIGNATURE_CFG, bufnr) -- no need to specify bufnr if you don't use toggle_key
require'lsp_signature'.on_attach(LSP_SIGNATURE_CFG) -- no need to specify bufnr if you don't use toggle_key


require('numb').setup()

require("goto-preview").setup {
        default_mappings=true;
}

lvim.builtin.treesitter.rainbow.enable = true

-- pyright 
local pyright_opts = {
        single_file_support = true,
        settings = {
                pyright = {
                        disableLanguageServices = false,
                        disableOrganizeImports = false,
                },
                python = {
                        analysis = {
                                autoImportCompletions = true,
                                autoSearchPaths = true,
                                diagnosticMode = "workspace",
                                typeCheckingMode = "basic",
                                useLibraryCodeForTypes = false
                        }
                },
        },
}
require("lvim.lsp.manager").setup("pyright", pyright_opts)
