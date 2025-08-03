, string num2){
        if (num1.size()<num2.size()) swap(num1, num2);
        string ans="";
        for (int i=num2.size()-1; i>=0; i--){
            string tmp=MultiOneNum(nu