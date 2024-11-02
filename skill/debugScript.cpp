g++ ac.cpp -o ac
g++ wa.cpp -o wa
$i = 0
while ($true) {
    Write-Output "$i"
    python gen.py > input
    Get-Content input | .\ac.exe > ac.out
    Get-Content input | .\wa.exe > wa.out
    $acOut = Get-Content .\ac.out
    $waOut = Get-Content .\wa.out
    if (diff $acOut $waOut) {
        diff $acOut $waOut
        break
    }
    $i++
}
