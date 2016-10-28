"GF command sourcefiles
let &path="src,"

nnoremap <F1> :Make -C build --no-print-directory -l<cr>
nnoremap <F3> :!./build/willin<cr>
nnoremap <F4> :Start gdb build/willin<cr>

nnoremap <F9> :Make -C build --no-print-directory clean<cr>
nnoremap <F10> :Make -C build --no-print-directory clean<cr>
nnoremap <F12> :Start! tiled<cr>

set makeprg=make\ -l\ --no-print-directory\ -C\ build
