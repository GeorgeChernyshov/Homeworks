select Country.Name
from Country left join City on City.CountryCode = Country.Code
group by Country.Code
having sum(City.Population) < 0.5*(Country.Population) and Country.Population > 0
order by Country.Name;
