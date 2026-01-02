// get api/user


export const getUserData = async (req , res) =>{
  try{
    const role = req.user.role;
    const recentSearchedCities = req.user.recentSearchedCities;
    res.json({success: true , role, recentSearchedCities})
  } catch(error){
    res.json({success: false , message: error.message})
  }
}


// store user recent searched cities

export const storeRecentSearchedCities = async (req, res)=>{
    try{
        const {recentSearchedCities} = req.body;
        const User =  req.user;

        if(User.recentSearchedCities.length < 3){
            User.recentSearchedCities.push(recentSearchedCities)
        }
        else{
            User.recentSearchedCities.shift();
            User.recentSearchedCities.push(recentSearchedCities)
        }
        await User.save();
        res.json({success: true , message: "city Added"})
    }
    catch(error) {
        res.json({success: false , message: error.message})
    }
};