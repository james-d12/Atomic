
$currentLocation = (Get-Location | Out-String)

Get-ChildItem -Path "./Dokky" -Recurse | Remove-Item -Force -Recurse -Confirm:$false
Remove-Item "./Dokky" -Recurse -Force -Confirm:$false

git clone https://github.com/james-d12/Dokky.git
Copy-Item ./docgen.json -Destination "./Dokky" 
Set-Location "./Dokky"
python ./generator.py ./docgen.json 
Set-Location "../"