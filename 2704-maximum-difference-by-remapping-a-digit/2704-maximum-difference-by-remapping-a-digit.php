class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function minMaxDifference($num) {
        $a = strval($num);
        $idx = 0;
        for($i = 0; $i < strlen($a); $i++){
            if ($a[$i] != '9'){
                $idx = $i;
                break;
            }
        }
        $a = str_replace($a[$idx], "9", $a);
    
        $b = strval($num);
        $b = str_replace($b[0], '0', $b);
        return intval($a) - intval($b);
    }
}