import os

header_text = '''
/*
 * =========================================================
 *____   ____     ___   ____  __  _   ___   __ __  ______  
 *|    \ |    \   /  _] /    ||  |/ ] /   \ |  |  ||      |
 *|  o  )|  D  ) /  [_ |  o  ||  ' / |     ||  |  ||      |
 *|     ||    / |    _]|     ||    \ |  O  ||  |  ||_|  |_|
 *|  O  ||    \ |   [_ |  _  ||     \|     ||  :  |  |  |  
 *|     ||  .  \|     ||  |  ||  .  ||     ||     |  |  |  
 *|_____||__|\_||_____||__|__||__|\_| \___/  \__,_|  |__|  
 * 
 * [filename]: [description]
 * 
 * =========================================================
 */
'''

for root, dirs, files in os.walk('.'):
    for file in files:
        if file.endswith('.cpp') or file.endswith('.hpp'):
            file_path = os.path.join(root, file)
            with open(file_path, 'r+') as f:
                content = f.read()
                if header_text.strip().replace('[filename]', file).replace('[description]', '') not in content:
                    f.seek(0, 0)
                    f.write(header_text.strip().replace('[filename]', file).replace('[description]', ''))
                    f.write('\n')
                    f.write(content)
                    f.truncate()