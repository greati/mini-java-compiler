echo "installing mini-java vim syntax..."
mkdir -p ~/.vim/syntax
cp mj.vim ~/.vim/syntax
mkdir -p ~/.vim/ftdetect
cp mj.vim.detect ~/.vim/ftdetect/mj.vim
echo "done, thanks!"
